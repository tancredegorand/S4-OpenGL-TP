#include "glm/ext/scalar_constants.hpp"
#include "p6/p6.h"
#include "glimac/default_shader.hpp"
#include "glm/glm.hpp"


struct Vertex2DColor{
    glm::vec2 position; 
    glm::vec3 color;
};


int main()
{
    auto ctx = p6::Context{{1280, 720, "TP3 EX2"}};
    ctx.maximize_window();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    const p6::Shader shader = p6::load_shader(
        "shaders/triangle.vs.glsl",
        "shaders/triangle.fs.glsl"
    );

    

    GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    
    const float rayon = 0.5f;
    const unsigned int pointNumber = 100;
    float              r           = 1.f;
    float              v           = 0.5f;
    float              b           = 0.f;
    

    Vertex2DColor vertices[3 * pointNumber];

    for (unsigned int i = 0; i < pointNumber; ++i) {
        float theta1 = static_cast<float>(i) * 2 * glm::pi<float>() / static_cast<float>(pointNumber);
        float theta2 = static_cast<float>(i + 1) * 2 * glm::pi<float>() / static_cast<float>(pointNumber);


        vertices[3 * i] = Vertex2DColor{{0.f, 0.f}, {1.f, 1.f, 1.f}}; // Centre du cercle
        vertices[3 * i + 1] = Vertex2DColor{{rayon * cos(theta1), rayon * sin(theta1)}, {r, v, b}};
        vertices[3 * i + 2] = Vertex2DColor{{rayon * cos(theta2), rayon * sin(theta2)}, {r, v, b}};


    }

  

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);


    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    static constexpr GLuint vertex_attr_position = 3;
    glEnableVertexAttribArray(vertex_attr_position);

    
    static constexpr GLuint vertex_attr_color = 8;
    glEnableVertexAttribArray(vertex_attr_color);



    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(vertex_attr_position, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), reinterpret_cast<void*>(offsetof(Vertex2DColor, position)));
    glVertexAttribPointer(vertex_attr_color, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), reinterpret_cast<void*>(offsetof(Vertex2DColor, color)));
        
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


 
    // Declare your infinite update loop.
    ctx.update = [&]() {
        /**********************²***********
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(vao);
        glimac::bind_default_shader();
        shader.use();
        glDrawArrays(GL_TRIANGLE_FAN, 0, 3 * pointNumber);

        glBindVertexArray(0);

        
        

    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
    glDeleteBuffers(1, &vbo); 
    glDeleteVertexArrays(1, &vao); 
}
