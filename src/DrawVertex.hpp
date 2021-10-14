#ifndef SHADERDRAW_HPP
#define SHADERDRAW_HPP

#include <type_traits>
#include <glad/glad.h>

class DrawVertex {
public:
    DrawVertex();
    virtual ~DrawVertex();
    virtual void render() const = 0;
protected:
    void bindVertexArray() const;
    void bufferData(float*, const std::size_t&) const;

    unsigned int VAO;
    unsigned int VBO;
};

#endif // SHADERDRAW_HPP
