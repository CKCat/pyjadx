/* Copyright 2018 R. Thomas
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <jadx/api/JavaField.hpp>

namespace jni::jadx::api {

JavaField::JavaField(JNIEnv& env, const Object_t& obj) {
  this->env_ = &env;
  this->obj_ = NewLocal(env, obj);
}

JavaField::JavaField(JNIEnv& env, const Object<>& obj) {

  this->env_ = &env;
  auto&& casted = Cast<JavaFieldTag>(this->env(), this->clazz(), obj);
  this->obj_ = NewLocal(env, casted);
}


bool JavaField::is_constructor(void) const {
  static auto&& isConstructor = this->clazz().template GetMethod<jboolean()>(this->env(), "isConstructor");
  return this->obj_.Call(this->env(), isConstructor);
}

bool JavaField::is_class_init(void) const {
  static auto&& isClassInit = this->clazz().template GetMethod<jboolean()>(this->env(), "isClassInit");
  return this->obj_.Call(this->env(), isClassInit);
}


}
