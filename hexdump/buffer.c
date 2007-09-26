


void*
AllocateLargeBuffer(
    unsigned long SuggestedSize,
    unsigned long* ActualSize
    )
{
    void* p;

    *ActualSize = 0;

    while (SuggestedSize != (size_t) SuggestedSize)
        SuggestedSize /= 2;

    while ((SuggestedSize != 0) && !(p = malloc(SuggestedSize)))
        SuggestedSize /= 2;

    *ActualSize = SuggestedSize;
    return p;
}

typedef struct _BufferStream_t
{
    void (*Flush)();
    void (*Fill)();
    void (*Read)();
    void (*Write)();

    unsigned char* Base;
    unsigned char* Position;
    unsigned char* End;

} _BufferStream_t;

typedef struct _BufferStdioStream_t
{
    void (*Flush)();
    void (*Fill)();
    void (*Read)();
    void (*Write)();

    unsigned char* Base;
    unsigned char* Position;
    unsigned char* End;

} _BufferStream_t;
