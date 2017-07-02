#ifndef __SIMPLE_BUFFER_H__
#define __SIMPLE_BUFFER_H__

#include <vector>
#include <string>
#include <stdint.h>

// only support little endian
class SimpleBuffer
{
public:
    SimpleBuffer();
    virtual ~SimpleBuffer();

public:
    void write_1byte(int8_t val);
    void write_2bytes(int16_t val);
    void write_3bytes(int32_t val);
    void write_4bytes(int32_t val);
    void write_8bytes(int64_t val);
    void write_string(std::string val);

public:
    int8_t read_1byte();
    int16_t read_2bytes();
    int32_t read_3bytes();
    int32_t read_4bytes();
    int64_t read_8bytes();
    std::string read_string(int len);

public:
    void skip(int size);
    bool require(int required_size);
    bool empty();
    int size();
    int pos();

public:
    std::string to_string();

private:
    std::vector<char> _data;
    int _pos;
};

#endif /* __SIMPLE_BUFFER_H__ */
