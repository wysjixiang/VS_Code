/*
    注： 如下函数fun(const std::string& str) 表示的是将str直接传给函数，而不是简单的拷贝一份。在前加const，表示不可修改str的值。
    因此注意这三种参数传递的区别！

    1.  fun(std::string str)
    2.  fun(std::string& str)
    3.  fun(const std::string& str)
*/