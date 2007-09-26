
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int close_brace = '}';

void
CleanupWhitespace(
    char * s
    )
{
    int ch0 = 1;
    char * t = s;
    char * start = s;
    while (1)
    {
        ch0 = *s;
        s += 1;
        switch (ch0)
        {
        case 0:
            *t++ = ch0;
            return;
        default:
            *t++ = ch0;
            break;
        case 10:
        case 13:
            s += strspn(s, "\r\n");
            while (t != start && ((ch0 = *(t - 1)) == 10 || ch0 == ' '))
            {
                t -= 1;
            }
            *t++ = 10;
            break;
        }
    }
}

void
RemoveEscapedCharacters(
    char * s
    )
{
    int ch0 = 1;
    int ch1 = 1;
    char *t = s;
    while (1)
    {
        ch0 = *s;
        s += 1;
        switch (ch0)
        {
        case 0:
            *t++ = ch0;
            return;
        default:
            *t++ = ch0;
            break;
        case '\\':
            ch1 = *s;
            s += 1;
            switch (ch1)
            {
            case 0:
                *t++ = ch0;
                *t++ = ch1;
                return;
            case '\'':
            case '\"':
            case '\\':
                *t++ = '1';
                *t++ = '2';
                break;
            }
        }
    }
}

void
RemoveStrings(
    char * s
    )
{
/*
only remove strings at the ends of lines
leave pinvoke strings alone
*/
    int ch0 = 1;
    char * t = s;
    char * u = 0;
    while (1)
    {
        ch0 = *s;
        switch (ch0)
        {
        case 0:
            *t++ = ch0;
            return;
        default:
            s += 1;
            *t++ = ch0;
            break;
        case '"':
            u = s;
            s += 1;
            while ((ch0 = *s) != 0 && ch0 != '"')
            {
                s += 1;
            }
            if (ch0  == '"')
            {
                s += 1;
                ch0 = *s;
                if (ch0 != '\n')
                {
                    memmove(t, u, (s - u));
                    t += (s - u);
                }
            }
        }
    }
}

void
RemoveSlashSlashComments(
    char * s
    )
{
    char * t = s;
#if 1
    char * s2;
    while ((s2 = strstr(s, "//")) != 0)
    {
        memmove(t, s, (s2 - s));
        t += (s2 - s);
        s2 = strchr(s2, 10);
        if (s2 != 0)
        {
            s = s2;
        }
        else
        {
            break;
        }
    }
    memmove(t, s, strlen(s) + 1);
#else
    int ch0 = 1;
    int ch1 = 1;
    while (ch0 != 0 && ch1 != 0)
    {
        ch0 = *s;
        switch (ch0)
        {
        default:
            s += 1;
            *t++ = ch0;
            break;
        case '/':
            ch1 = *(s + 1);
            s += 2;
            switch (ch1)
            {
            default:
                *t++ = ch0;
                *t++ = ch1;
                break;
            case '/':
                *t++ = '\n';
                while ((ch0 = *s) != 0 && ch0 != '\n')
                {
                    s += 1;
                }
                break;
            }
            break;
        }
    }
#endif
}

void
RemoveIlInstructions(
    char * s
    )
{
    /*
    IL instruction ends at closing brace or . at start of line preceded by optional space
    */
    char * t = s;
    char * start = s;
    char * end = start + strlen(start);
    char * line_start = 0;
    const static char mark1[] = "IL_";
    const static char mark2[] = ":  ";
    int ch0;
    while (1)
    {
        ch0 = *s;
        switch (ch0)
        {
        default:
            s += 1;
            *t++ = ch0;
            break;
        case 0:
            s += 1;
            *t++ = 0;
            return;
        case '\n':
            line_start = s;
            s += 1;
            while (*s == ' ')
            {
                ++s;
            }
            if (memcmp(s, mark1, sizeof(mark1) - 1) == 0
                && (s + sizeof(mark1) - 1 + 4 + sizeof(mark2) - 1) < end
                && memcmp(s + sizeof(mark1) - 1 + 4, mark2, sizeof(mark2) - 1) == 0
                )
            {
                char * u;
                u = strchr(s, close_brace);
                if (u != 0)
                {
                    while (u != start && *(u - 1) == ' ')
                    {
                        u -= 1;
                    }
                    s = u;
                    break;
                }
                else
                {
                    fprintf(stderr, "error\n");
                    exit(-1);
                }
            }
            else
            {
                memmove(t, line_start, (s - line_start));
                t += (s - line_start);
            }
            break;
        }
    }
}

char *
skip_custom(
    char * s
    )
{
    s = strsr(s, " = )");
    if (s == 0)
        return s;
    return strchr(s, ')');
}
#define skip_permissionset skip_custom

void
RemoveStuff(
    char * s
    )
{
    char * t = s;
    char * line_start = 0;
    char * start = s;
    const static char initial_dot_chars[] = "cplm"; /* custom permissionset locals minstack */
    const static struct {
        char * mark;
        char * skip(char *);
    } marks[] = {
    	{ ".custom ", skip_custom },
        { ".permissionset ", skip_permissionset }
    };
    int ch0;
    while (1)
    {
        ch0 = *s;
        switch (ch0)
        {
        default:
            s += 1;
            *t++ = ch0;
            break;
        case 0:
            s += 1;
            *t++ = 0;
            return;
        case 10:
            line_start = s;
            s += 1;
            s += strspn(s, " ");
            if (*s == '.' && (memcmp(s, mark1, sizeof(mark1) - 1) == 0 || memcmp(s, mark2, sizeof(mark2) - 1) == 0))
            {
                char * u;
                u = strstr(s, " = (");
                if (u != 0)
                {
                    u = strchr(u, ')');
                }
                if (u != 0)
                {
                    if (t == start || *(t - 1) != 10)
                    {
                        *t++ = 10;
                    }
                    s = u + 1;
                    break;
                }
                else
                {
                    fprintf(stderr, "error\n");
                    exit(-1);
                }
            }
            else
            {
                memmove(t, line_start, (s - line_start));
                t += (s - line_start);
            }
            break;
        }
    }
}

void
LogAndRun(
    const char * s,
    void (*function)(char *),
    char * buffer
    )
{
    printf("%s", s);
    fflush(stdout);
    (*function)(buffer);
    printf(".\n");
}

int main(int argc, char ** argv)
{
    FILE * file_in = 0;
    FILE * file_out = 0;
    char * buffer = 0;
    unsigned long size = (1UL << 24);
    const unsigned long read_size = (1UL << 24);
    unsigned long bytes_read = 0;
    
    file_in = fopen(argv[1], "rb");
    buffer = (char*)realloc(buffer, size);
    while ((bytes_read = fread(buffer + size - read_size, 1, read_size, file_in)) == read_size)
    {
        size += read_size;
        buffer = (char*)realloc(buffer, size);
    }
    size += bytes_read;
    buffer = (char*)realloc(buffer, size + 1);
    buffer[size] = 0;

    fclose(file_in);
    file_in = 0;
    file_out = fopen(argv[2], "wb");
 
    LogAndRun("CleanupWhitespace", CleanupWhitespace, buffer);
    LogAndRun("RemoveEscapedCharacters", RemoveEscapedCharacters, buffer);
    LogAndRun("RemoveStrings", RemoveStrings, buffer);
    LogAndRun("RemoveSlashSlashComments", RemoveSlashSlashComments, buffer);
    LogAndRun("RemoveIlInstructions", RemoveIlInstructions, buffer);
    LogAndRun("RemoveStuff", RemoveStuff, buffer);
    LogAndRun("CleanupWhitespace", CleanupWhitespace, buffer);

    printf("fwrite"); fflush(stdout);
    fwrite(buffer, 1, strlen(buffer), file_out);
    printf(".\n");
    
    fclose(file_out);
    file_out = 0;

    return 0;
}
