/*
 * Copyright 2021 kenney
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "include/Material.h"
#include "include/Common.h"

namespace engin {

Material::Material(GLuint baseColorTexture, int baseColorTextureLocation)
    : baseColorTexture_(baseColorTexture),
      baseColorTextureLocation_(baseColorTextureLocation) {}
void Material::bind() {
  GL_CHECK(glActiveTexture(GL_TEXTURE0));
  GL_CHECK(glBindTexture(GL_TEXTURE_2D, baseColorTexture_));
  GL_CHECK(glUniform1i(baseColorTextureLocation_, 0));
}

} // namespace engin
