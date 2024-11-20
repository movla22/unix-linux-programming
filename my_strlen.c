#include <stdio.h>

/*size_t my_strlen(const char* str) {
    const char* s = str;

    if (str == NULL) {
        return 0;
    }else{
       while (*s) s++;
       return s - str;
    }
}*/


//size_t my_strlen(const char* str) {
//    const char* s = str;
//    while (*s) s++;
//    return s - str;
//}
//

//size_t my_strlen(const char* str) {
//    if (!str) return 0;
//    const char* s = str;
//    while (*s) s++;
//    return s - str;
//}

size_t my_strlen(const char* str) {
    /*if (!str) return 0;*/

    const char* s = str;
    while (*s) s++;
    return s - str;
}


int main() {
    const char* text = "hello";

    printf("%zu\n", my_strlen(text));
    return 0;
}
