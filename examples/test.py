#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2021-06-11 11:49:08
# @Author  : CKCat (ckcatck@qq.com)
# @Link    : https://github.com/CKCat
# @Version : 1.0.0

import os
import pyjadx

jadx = pyjadx.Jadx()
app = jadx.load("com.passwordchecker.apk")

for cls in app.classes:
    if cls.name == "PasswordChecker":
        print(cls.fullname)
        for md in cls.methods:
            print(md.fullname + " " + md.return_type.primitive_type.longname)
        for field in cls.fields:
            print(field.fullname)

        print(type(cls))



