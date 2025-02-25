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
#ifndef JADX_API_JAVA_FIELD_H_
#define JADX_API_JAVA_FIELD_H_

#include <jni/jni.hpp>

#include <jadx/api/JavaNode.hpp>
//#include <jadx/api/JavaClass.hpp>
#include <jadx/info/AccessInfo.hpp>
#include <jadx/args/ArgType.hpp>
#include <java/util/List.hpp>

#include <string>

namespace jni::jadx::api {

struct JavaFieldTag { static constexpr auto Name() { return "jadx/api/JavaField"; } };
class JavaField : public JavaNode<JavaField, JavaFieldTag, Object<JavaFieldTag>, Class<JavaFieldTag>> {
  public:

  using Object_t = Object<JavaFieldTag>;
  using Class_t  = Class<JavaFieldTag>;

  JavaField(JNIEnv& env, const Object_t& obj);
  JavaField(JNIEnv& env, const Object<>& obj);

  bool is_constructor(void) const;
  bool is_class_init(void) const;


  CREATE_GETTER_OBJECT(jni::jadx::info::AccessInfo, getAccessFlags);
  CREATE_GETTER_OBJECT(jni::jadx::args::ArgType, getType);
};

}
#endif
