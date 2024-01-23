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

    Vertex2DColor vertices[] = { 
        Vertex2DColor{{-0.5f, -0.5f}, {1.f, 0.f, 0.f}}, // Premier sommet
        Vertex2DColor{{ 0.5f, -0.5f}, {0.f, 1.f, 0.f}}, // Deuxième sommet
        Vertex2DColor{{ 0.0f,  0.5f}, {0.f, 0.f, 1.f}}  // Troisième sommet
    };

    
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW);

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
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        
        

    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
    glDeleteBuffers(1, &vbo); 
    glDeleteVertexArrays(1, &vao); 
}
