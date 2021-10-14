#ifndef SHADERDRAW_HPP
#define SHADERDRAW_HPP

#include <type_traits>
#include <glad/glad.h>
#include "UIComponent.hpp"

class DrawVertex : public UIComponent {
public:
    DrawVertex();
    virtual ~DrawVertex();
protected:
    void bindVertexArray() const;
    void bufferData(float*, const std::size_t&) const;
protected:
    unsigned int VAO;
    unsigned int VBO;
};

#endif // SHADERDRAW_HPP
