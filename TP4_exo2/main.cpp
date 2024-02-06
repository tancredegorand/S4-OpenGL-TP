// // creat unique VBO



// class UniqueBuffer {
// public:
//     UniqueBuffer()
//     {
//         glGenBuffers(1, &_id); // Do whatever you need to create the resource
//     }
//     ~UniqueBuffer()
//     {
//         glDeleteBuffers(1, &_id); // Do whatever you need to delete the resource
//     }
//     UniqueBuffer(const UniqueBuffer&) = delete;            // We disable copying
//     UniqueBuffer& operator=(const UniqueBuffer&) = delete; // We disable copying
//     UniqueBuffer(UniqueBuffer&& other) noexcept // Move constructor
//         : _id{other._id}
//     {
//         other._id = 0; // Make sure that other won't delete the _id we just copied
//     }
//     UniqueBuffer& operator=(UniqueBuffer&& other) noexcept // Move assignment operator
//     {
//         if (this != &other) {         // Make sure that we don't do silly things when we try to move an object to itself
//             glDeleteBuffers(1, &_id); // Delete the previous object
//             _id     = other._id;      // Copy the object
//             other._id = 0;            // Make sure that other won't delete the _id we just copied
//         }
//         return *this; // move assignment must return a reference to this, so we do it
//     }

//     GLuint id() const { return _id; } // The getter for the wrapped `_id`.

// private:
//     GLuint _id;
// };

