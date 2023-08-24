#pragma once
/// <summary>
/// The Message struct represents a message with associated information
/// </summary>
typedef struct Message
{
    double val;         // The value of the message
    size_t size_tid;    // The size or thread ID associated with the message
    bool is_finish;     // A flag indicating if this is the final message
}Message;