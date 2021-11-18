#include <cstddef>
#include <stdio.h>


#include "include/GraphicGL40.h"


namespace engin {
	EventBase * GraphicGL40::eventBase = nullptr;



	bool GraphicGL40::create(int widht, int height){
		printf("GraphicGL40 init start ! \n");

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		window = glfwCreateWindow(widht, height, "lean gl",NULL, NULL);
		if(window == NULL){
			printf("Failed to create GLFW window ! \n");
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		glfwSetCursorPosCallback(window, mouse_callback);
		glfwSetScrollCallback(window, scroll_callback);

		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
			printf("Failed to initialize GLAD ! \n");
			return -1;
		}
		glViewport(0,0,widht,height);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


		return true;
	}


		bool GraphicGL40::setEventCallback(EventBase* base) {
			GraphicGL40::eventBase = base;
			return true;
		}


		int GraphicGL40::clearPreFrame() {
			glClearColor(0.8f, 0.5f, 0.5f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			return 0;
		}


		int GraphicGL40::renderFrame(){

			if(!glfwWindowShouldClose(window)){
				processInput(window);
				glfwPollEvents();
			}

			glfwSwapBuffers(window);
			return 0;
		}



		bool GraphicGL40::release(){
			glfwTerminate();
			return true;
		}


		void GraphicGL40::processInput(GLFWwindow* window){

			if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
				glfwSetWindowShouldClose(window, true);				
			}

			if(this->eventBase == nullptr){
				return ;
			}

			if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
				// opt -> proceessKeyEvent(GLFW_KEY_W);
				this->eventBase->proceessKeyEvent('W');
			}
			if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
				// opt -> proceessKeyEvent(GLFW_KEY_A);
				this->eventBase->proceessKeyEvent('A');
			}
			if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
				// opt -> proceessKeyEvent(GLFW_KEY_D);
				this->eventBase->proceessKeyEvent('D');
			}
			if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
				// opt -> proceessKeyEvent(GLFW_KEY_S);
				this->eventBase->proceessKeyEvent('S');
			}
			
		}

		void GraphicGL40::mouse_callback(GLFWwindow * window, double xoffset, double yoffset){
			// Single::instance.getOperator()->mouse_callback(xoffset, yoffset);
			if(GraphicGL40::eventBase == nullptr){
				return ;
			}
			GraphicGL40::eventBase->mouse_callback(xoffset, yoffset);
		}

		void GraphicGL40::scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
			// Single::instance.getOperator()->scroll_callback(xoffset, yoffset);
			if(GraphicGL40::eventBase == nullptr){
				return ;
			}
			GraphicGL40::eventBase->scroll_callback(xoffset, yoffset);

		};



		void GraphicGL40::drawNode(tinygltf::Model &model, const tinygltf::Node &node){

			if (node.mesh > -1) {
				assert(node.mesh < model.meshes.size());
				DrawMesh(model, model.meshes[node.mesh]);



			}

			// Draw child nodes.
			for (size_t i = 0; i < node.children.size(); i++) {
				assert(node.children[i] < model.nodes.size());
				drawNode(model, model.nodes[node.children[i]]);
			}


		}

		float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};



	void GraphicGL40::DrawTest(){


		// glGenVertexArrays(1, &VAO);
		// glGenBuffers(1, &VBO);

		// glBindBuffer(GL_ARRAY_BUFFER, VBO);
		// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// glBindVertexArray(VAO);
		// glEnableVertexAttribArray(0);
		// glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 5* sizeof(float), (void*)0);


		// // glUseProgram(shaderProgram);
		// glDrawArrays(GL_TRIANGLES, 0, 3);
		// glBindVertexArray(0);  


	}

	void GraphicGL40::DrawMesh(tinygltf::Model &model, const tinygltf::Mesh &mesh) {
	// Skip curves primitive.
	//   if (gCurvesMesh.find(mesh.name) != gCurvesMesh.end()) {
	//    return;
	//   }

	//   if (gGLProgramState.uniforms["diffuseTex"] >= 0) {
	//    glUniform1i(gGLProgramState.uniforms["diffuseTex"], 0);  // TEXTURE0
	//   }

	}


	std::shared_ptr<std::vector<unsigned int>> GraphicGL40::buildBuffers(const tinygltf::Model &model){
		auto buffers = std::make_shared<std::vector<GLuint>>(model.buffers.size(), 0);
		GL_CHECK(glGenBuffers(buffers->size(), buffers->data()));
		for (auto i = 0; i < model.buffers.size(); ++i) {
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, buffers->at(i)));
			GL_CHECK(glBufferData(GL_ARRAY_BUFFER, model.buffers[i].data.size(),
								model.buffers[i].data.data(), GL_STATIC_DRAW));
		}
		GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, 0));
		return buffers;
	}

	std::shared_ptr<std::vector<unsigned int>> GraphicGL40::buildTextures(const tinygltf::Model &model){
	auto textures = std::make_shared<std::vector<GLuint>>(model.textures.size());
	GL_CHECK(glGenTextures(textures->size(), textures->data()));
	for (auto i = 0; i < textures->size(); ++i) {
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, textures->at(i)));
		const auto &texture = model.textures[i];
		const auto &image = model.images[texture.source];
		auto minFilter =
			texture.sampler >= 0 && model.samplers[texture.sampler].minFilter != -1
				? model.samplers[texture.sampler].minFilter
				: GL_LINEAR;
		auto magFilter =
			texture.sampler >= 0 && model.samplers[texture.sampler].magFilter != -1
				? model.samplers[texture.sampler].magFilter
				: GL_LINEAR;
		auto wrapS = texture.sampler >= 0 ? model.samplers[texture.sampler].wrapS
										: GL_REPEAT;
		auto wrapT = texture.sampler >= 0 ? model.samplers[texture.sampler].wrapT
										: GL_REPEAT;
		GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height,
							0, GL_RGBA, image.pixel_type, image.image.data()));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT));
		if (minFilter == GL_NEAREST_MIPMAP_NEAREST ||
			minFilter == GL_NEAREST_MIPMAP_LINEAR ||
			minFilter == GL_LINEAR_MIPMAP_NEAREST ||
			minFilter == GL_LINEAR_MIPMAP_LINEAR) {
		GL_CHECK(glGenerateMipmap(GL_TEXTURE_2D));
		}
	}
	GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
	return textures;

	}


	std::shared_ptr<Mesh>
	GraphicGL40::buildMesh(const tinygltf::Model &model, unsigned int meshIndex,
					const std::shared_ptr<std::vector<GLuint>> &buffers,
					const std::shared_ptr<std::vector<GLuint>> &textures) {
	auto meshPrimitives =
		std::make_shared<std::vector<std::shared_ptr<Primitive>>>();
	const auto &primitives = model.meshes[meshIndex].primitives;
	auto vaos = std::make_shared<std::vector<GLuint>>(primitives.size());
	GL_CHECK(glGenVertexArrays(vaos->size(), vaos->data()));
	for (auto i = 0; i < primitives.size(); ++i) {
		GL_CHECK(glBindVertexArray(vaos->at(i)));
		meshPrimitives->push_back(
			buildPrimitive(model, meshIndex, i, vaos, buffers, textures));
	}
	GL_CHECK(glBindVertexArray(0));
	return std::make_shared<Mesh>(meshPrimitives);
	}


	std::shared_ptr<Primitive>
	GraphicGL40::buildPrimitive(const tinygltf::Model &model, unsigned int meshIndex,
						unsigned int primitiveIndex,
						const std::shared_ptr<std::vector<GLuint>> &vaos,
						const std::shared_ptr<std::vector<GLuint>> &buffers,
						const std::shared_ptr<std::vector<GLuint>> &textures) {
	const auto &primitive = model.meshes[meshIndex].primitives[primitiveIndex];
	for (auto &attribute : preDefinedAttributes) {
		const auto &attributeName = attribute.first;
		const auto &attributeLocation = attribute.second;
		const auto iterator = primitive.attributes.find(attributeName);
		if (iterator == primitive.attributes.end()) {
		continue;
		}
		const auto &accessor = model.accessors[(*iterator).second];
		const auto &bufferView = model.bufferViews[accessor.bufferView];
		const auto bufferIdx = bufferView.buffer;

		GL_CHECK(glEnableVertexAttribArray(attributeLocation));
		GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, buffers->at(bufferIdx)));

		const auto byteOffset = accessor.byteOffset + bufferView.byteOffset;
		GL_CHECK(glVertexAttribPointer(
			attributeLocation, accessor.type, accessor.componentType, GL_FALSE,
			bufferView.byteStride, (const GLvoid *)byteOffset));
	}
	std::shared_ptr<Primitive> meshPrimitive;
	if (primitive.indices >= 0) {
		const auto &accessor = model.accessors[primitive.indices];
		const auto &bufferView = model.bufferViews[accessor.bufferView];
		const auto bufferIndex = bufferView.buffer;
		GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers->at(bufferIndex)));
		meshPrimitive = std::make_shared<Primitive>(
			vaos->at(primitiveIndex), primitive.mode, accessor.count,
			accessor.componentType, accessor.byteOffset + bufferView.byteOffset);
	} else {
		const auto accessorIndex = (*begin(primitive.attributes)).second;
		const auto &accessor = model.accessors[accessorIndex];
		meshPrimitive =
			std::make_shared<Primitive>(vaos->at(primitiveIndex), primitive.mode,
										accessor.count, accessor.componentType);
	}
	meshPrimitive->setMaterial(
		buildMaterial(model, primitive.material, textures));
	return meshPrimitive;
	}


	std::shared_ptr<Material>
	GraphicGL40::buildMaterial(const tinygltf::Model &model, unsigned int materialIndex,
						const std::shared_ptr<std::vector<GLuint>> &textures) {
	auto baseColorIndex = model.materials[materialIndex]
								.pbrMetallicRoughness.baseColorTexture.index;
	auto baseColorTexture =
		(baseColorIndex >= 0 ? textures->at(baseColorIndex)
							: buildDefaultBaseColorTexture(model));
	const auto baseColorTextureLocation = GL_CHECK(
		glGetUniformLocation(program_->getProgram(), UNIFORM_BASE_COLOR_TEXTURE));
	return std::make_shared<Material>(baseColorTexture, baseColorTextureLocation);
	}

}