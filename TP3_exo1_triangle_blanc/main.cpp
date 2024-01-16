#include "p6/p6.h"

int main()
{
    auto ctx = p6::Context{{1280, 720, "TP3 EX1"}};
    ctx.maximize_window();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    GLfloat vertices[] = {
      -0.5f, -0.5f, 
      0.5f, -0.5f,
      0.0f,0.5f  
    };
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);


    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    static constexpr GLuint vertex_attr_position = 0;
    glEnableVertexAttribArray(vertex_attr_position);

    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(vertex_attr_position, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

   glBindBuffer(GL_ARRAY_BUFFER, 0);
 
    // Declare your infinite update loop.
    ctx.update = [&]() {
        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
}