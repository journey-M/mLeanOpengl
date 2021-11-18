// #include "include/GLNode.h"
// #include <cstddef>
// #include <cstdio>


// // GLNode::GLNode(){
// // 	this->shader = std::make_shared<Shader>("/home/gwj/workspaces/TowerDefends/engin/res/texture.vs", "/home/gwj/workspaces/TowerDefends/engin/res/texture.fs");
// // }

// void GLNode::setMeshData(tinygltf::Model &model,  tinygltf::Mesh &mesh) {    
//     this->mesh = mesh;
//     this->model = model;
// }

// bool GLNode::checkInit(){
//     // if (inited) {
//     //     return true;
//     // }

// 	std::cout << "GLNode check Init"<<std::endl;

// 	SetupMeshState(model);

//     initTexture();

//     inited = true;
//     return inited;
// }


// void GLNode::SetupMeshState(tinygltf::Model &model)
//   // Buffer
//   {
//     for (size_t i = 0; i < model.bufferViews.size(); i++) {
//       const tinygltf::BufferView &bufferView = model.bufferViews[i];
//       if (bufferView.target == 0) {
//         std::cout << "WARN: bufferView.target is zero" << std::endl;
//         continue;  // Unsupported bufferView.
//       }

//       int sparse_accessor = -1;
//       for (size_t a_i = 0; a_i < model.accessors.size(); ++a_i) {
//         const auto &accessor = model.accessors[a_i];
//         if (accessor.bufferView == i) {
//           std::cout << i << " is used by accessor " << a_i << std::endl;
//           if (accessor.sparse.isSparse) {
//             std::cout
//                 << "WARN: this bufferView has at least one sparse accessor to "
//                    "it. We are going to load the data as patched by this "
//                    "sparse accessor, not the original data"
//                 << std::endl;
//             sparse_accessor = a_i;
//             break;
//           }
//         }
//       }

//       const tinygltf::Buffer &buffer = model.buffers[bufferView.buffer];
//       GLBufferState state;
//       glGenBuffers(1, &state.vb);
//       glBindBuffer(bufferView.target, state.vb);
//       std::cout << "buffer.size= " << buffer.data.size()
//                 << ", byteOffset = " << bufferView.byteOffset << std::endl;

//       if (sparse_accessor < 0)
//         glBufferData(bufferView.target, bufferView.byteLength,
//                      &buffer.data.at(0) + bufferView.byteOffset,
//                      GL_STATIC_DRAW);
//       else {
//         const auto accessor = model.accessors[sparse_accessor];
//         // copy the buffer to a temporary one for sparse patching
//         unsigned char *tmp_buffer = new unsigned char[bufferView.byteLength];
//         memcpy(tmp_buffer, buffer.data.data() + bufferView.byteOffset,
//                bufferView.byteLength);

//         const size_t size_of_object_in_buffer =
//             ComponentTypeByteSize(accessor.componentType);
//         const size_t size_of_sparse_indices =
//             ComponentTypeByteSize(accessor.sparse.indices.componentType);

//         const auto &indices_buffer_view =
//             model.bufferViews[accessor.sparse.indices.bufferView];
//         const auto &indices_buffer = model.buffers[indices_buffer_view.buffer];

//         const auto &values_buffer_view =
//             model.bufferViews[accessor.sparse.values.bufferView];
//         const auto &values_buffer = model.buffers[values_buffer_view.buffer];

//         for (size_t sparse_index = 0; sparse_index < accessor.sparse.count;
//              ++sparse_index) {
//           int index = 0;
//           // std::cout << "accessor.sparse.indices.componentType = " <<
//           // accessor.sparse.indices.componentType << std::endl;
//           switch (accessor.sparse.indices.componentType) {
//             case TINYGLTF_COMPONENT_TYPE_BYTE:
//             case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
//               index = (int)*(
//                   unsigned char *)(indices_buffer.data.data() +
//                                    indices_buffer_view.byteOffset +
//                                    accessor.sparse.indices.byteOffset +
//                                    (sparse_index * size_of_sparse_indices));
//               break;
//             case TINYGLTF_COMPONENT_TYPE_SHORT:
//             case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
//               index = (int)*(
//                   unsigned short *)(indices_buffer.data.data() +
//                                     indices_buffer_view.byteOffset +
//                                     accessor.sparse.indices.byteOffset +
//                                     (sparse_index * size_of_sparse_indices));
//               break;
//             case TINYGLTF_COMPONENT_TYPE_INT:
//             case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
//               index = (int)*(
//                   unsigned int *)(indices_buffer.data.data() +
//                                   indices_buffer_view.byteOffset +
//                                   accessor.sparse.indices.byteOffset +
//                                   (sparse_index * size_of_sparse_indices));
//               break;
//           }
//           std::cout << "updating sparse data at index  : " << index
//                     << std::endl;
//           // index is now the target of the sparse index to patch in
//           const unsigned char *read_from =
//               values_buffer.data.data() +
//               (values_buffer_view.byteOffset +
//                accessor.sparse.values.byteOffset) +
//               (sparse_index * (size_of_object_in_buffer * accessor.type));

//           /*
//           std::cout << ((float*)read_from)[0] << "\n";
//           std::cout << ((float*)read_from)[1] << "\n";
//           std::cout << ((float*)read_from)[2] << "\n";
//           */

//           unsigned char *write_to =
//               tmp_buffer + index * (size_of_object_in_buffer * accessor.type);

//           memcpy(write_to, read_from, size_of_object_in_buffer * accessor.type);
//         }

//         // debug:
//         /*for(size_t p = 0; p < bufferView.byteLength/sizeof(float); p++)
//         {
//           float* b = (float*)tmp_buffer;
//           std::cout << "modified_buffer [" << p << "] = " << b[p] << '\n';
//         }*/

//         glBufferData(bufferView.target, bufferView.byteLength, tmp_buffer,
//                      GL_STATIC_DRAW);
//         delete[] tmp_buffer;
//       }
//       glBindBuffer(bufferView.target, 0);

//       gBufferState[i] = state;
//     }
//   }


// void GLNode::initTexture(){
//     glGenTextures(1, &texture);
//     glBindTexture(GL_TEXTURE_2D, texture);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     int width, height, nrChannels;
//     // unsigned char *data = stbi_load("/home/gwj/workspaces/TowerDefends/engin/res/container.jpg", &width, &height, &nrChannels, 0);
//     // if (data)
//     // {
//     //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//     //     glGenerateMipmap(GL_TEXTURE_2D);
//     // }
//     // else
//     // {
//     //     std::cout << "Failed to load texture" << std::endl;
//     // }
//     // stbi_image_free(data);
// }


// void GLNode::drawObject() {

// //     GLenum error = glGetError();
// //     if (error != GL_NO_ERROR) {
// //         printf(" opengl  渲染前错误  %d \n", error);
// //     }

// //    // printf("this is in Texture... \n");
// //     glBindTexture(GL_TEXTURE_2D ,texture);

// //     glBindVertexArray(VAO); 
// // 	// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
// // 	glDrawArrays(GL_TRIANGLES, 0, 6);

// //     glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    

// //     error = glGetError();
// //     if (error != GL_NO_ERROR) {

// //         printf(" opengl  渲染后错误  %x \n", error);
// //     }



//     for (size_t i = 0; i < mesh.primitives.size(); i++) {
//         const tinygltf::Primitive &primitive = mesh.primitives[i];

//         if (primitive.indices < 0) return;

//         // Assume TEXTURE_2D target for the texture object.
//         // glBindTexture(GL_TEXTURE_2D, gMeshState[mesh.name].diffuseTex[i]);

//         std::map<std::string, int>::const_iterator it(primitive.attributes.begin());
//         std::map<std::string, int>::const_iterator itEnd(
//             primitive.attributes.end());

//         for (; it != itEnd; it++) {
//             assert(it->second >= 0);
//             const tinygltf::Accessor &accessor = model.accessors[it->second];
//             glBindBuffer(GL_ARRAY_BUFFER, gBufferState[accessor.bufferView].vb);
//             CheckErrors("bind buffer");

//             int size = 1;
//             if (accessor.type == TINYGLTF_TYPE_SCALAR) {
//                 size = 1;
//             } else if (accessor.type == TINYGLTF_TYPE_VEC2) {
//                 size = 2;
//             } else if (accessor.type == TINYGLTF_TYPE_VEC3) {
//                 size = 3;
//             } else if (accessor.type == TINYGLTF_TYPE_VEC4) {
//                 size = 4;
//             } else {
//                 assert(0);
//             }
//             // it->first would be "POSITION", "NORMAL", "TEXCOORD_0", ...
//             if ((it->first.compare("POSITION") == 0) ||
//                 (it->first.compare("NORMAL") == 0) ||
//                 (it->first.compare("TEXCOORD_0") == 0)) {
//                 if (gGLProgramState.attribs[it->first] >= 0) {
//                 // Compute byteStride from Accessor + BufferView combination.
//                 int byteStride =
//                     accessor.ByteStride(model.bufferViews[accessor.bufferView]);
//                 assert(byteStride != -1);
//                 glEnableVertexAttribArray(gGLProgramState.attribs[it->first]);
//                 glVertexAttribPointer(gGLProgramState.attribs[it->first], size,
//                                         accessor.componentType,
//                                         accessor.normalized ? GL_TRUE : GL_FALSE,
//                                         byteStride, BUFFER_OFFSET(accessor.byteOffset));
//                 CheckErrors("vertex attrib pointer");
//                 glEnableVertexAttribArray(gGLProgramState.attribs[it->first]);
//                 CheckErrors("enable vertex attrib array");

//                 }
//             }
//         }

//         const tinygltf::Accessor &indexAccessor =
//             model.accessors[primitive.indices];
//         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
//                     gBufferState[indexAccessor.bufferView].vb);
//         CheckErrors("bind buffer");
//         int mode = -1;
//         if (primitive.mode == TINYGLTF_MODE_TRIANGLES) {
//         mode = GL_TRIANGLES;
//         } else if (primitive.mode == TINYGLTF_MODE_TRIANGLE_STRIP) {
//         mode = GL_TRIANGLE_STRIP;
//         } else if (primitive.mode == TINYGLTF_MODE_TRIANGLE_FAN) {
//         mode = GL_TRIANGLE_FAN;
//         } else if (primitive.mode == TINYGLTF_MODE_POINTS) {
//         mode = GL_POINTS;
//         } else if (primitive.mode == TINYGLTF_MODE_LINE) {
//         mode = GL_LINES;
//         } else if (primitive.mode == TINYGLTF_MODE_LINE_LOOP) {
//         mode = GL_LINE_LOOP;
//         } else {
//         assert(0);
//         }
//         glDrawElements(mode, indexAccessor.count, indexAccessor.componentType,
//                     BUFFER_OFFSET(indexAccessor.byteOffset));
//         CheckErrors("draw elements");

//         {
//         std::map<std::string, int>::const_iterator it(
//             primitive.attributes.begin());
//         std::map<std::string, int>::const_iterator itEnd(
//             primitive.attributes.end());

//         for (; it != itEnd; it++) {
//             if ((it->first.compare("POSITION") == 0) ||
//                 (it->first.compare("NORMAL") == 0) ||
//                 (it->first.compare("TEXCOORD_0") == 0)) {
//             if (gGLProgramState.attribs[it->first] >= 0) {
//                 glDisableVertexAttribArray(gGLProgramState.attribs[it->first]);
//             }
//             }
//         }
//         }
//     }


// }