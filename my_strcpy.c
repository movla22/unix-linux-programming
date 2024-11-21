#include <stdio.h>

//void my_strcpy(char* dest, const char* src) {
//    while (*src != '\0') {
//        *dest = *src;
//        dest++;
//        src++;
//    }
//    *dest = '\0';
//}

void my_strcpy(char* dest, const char* src) {
    while ((*dest++ = *src++)); // Null karakter dahil kopyalanır
}


int main() {
    const char* source = "merhaba";
    char destination[50];
    my_strcpy(destination, source);
   
    printf("%s", destination);

    return 0;
}



Bu kod, bir karakter dizisini (src) diğerine (dest) kopyalayan bir fonksiyon olan my_strcpy fonksiyonunu tanımlar. Kopyalama işlemi şu şekilde gerçekleşir:

1. *dest++ = *src++ İfadesi:
*dest = *src: src işaretçisinin işaret ettiği karakteri, dest işaretçisinin işaret ettiği konuma kopyalar.
dest++: dest işaretçisi bir sonraki bellek adresine kaydırılır.
src++: src işaretçisi bir sonraki bellek adresine kaydırılır.
Bu işlem, bir karakteri kopyalayıp işaretçileri ilerletir.

2. while Döngüsü:
(*dest++ = *src++): Bu ifade, eşitlik işleminin sonucunu döndürür. Eğer src tarafından işaret edilen karakter '\0' (null karakter) değilse, bu ifadenin sonucu true olur ve döngü devam eder.
Null karakter ('\0') kopyalandığında, bu karakterin değeri 0 olduğundan, döngü sona erer.
3. Null Karakterin Kopyalanması:
Döngü, src dizisinin sonundaki '\0' karakterini de kopyalar. Bu sayede kopyalanan dizinin sonu da doğru bir şekilde işaretlenir.
Satır Satır İşleme:
Örnek: src = "abc"

Adım	*src	*dest	İşlem	Sonuç
1	'a'	'a'	'a' kopyalanır, işaretçiler ilerler	dest = "a"
2	'b'	'b'	'b' kopyalanır, işaretçiler ilerler	dest = "ab"
3	'c'	'c'	'c' kopyalanır, işaretçiler ilerler	dest = "abc"
4	'\0'	'\0'	Null karakter kopyalanır, döngü biter	dest = "abc\0"
Neden Bu Kadar Kısa?
C'nin Operatör Mantığı:

C'de bir ifade (*dest++ = *src++) hem işlem yapar hem de bir sonuç döndürür.
Bu sayede işlem ve kontrol aynı satırda yapılabilir.
Null Kontrolü:

while döngüsündeki ifade, null karaktere ulaşılıp ulaşılmadığını da otomatik olarak kontrol eder. Ek bir if yapısına gerek yoktur.
İşaretçilerin Kullanımı:

İşaretçiler, dizinin her elemanını dolaşmak ve üzerinde işlem yapmak için doğrudan bellek adresleriyle çalışır. Bu, hem hızlı hem de minimal bir kod yazımı sağlar.
Bu Yöntemin Avantajları:
Kısa ve Okunaklı:
Tüm işlemler tek bir satırda yapılır. Gereksiz kod yazımı ortadan kalkar.
Performans:
İşaretçiler ve bellek erişimi doğrudan kullanıldığı için çok hızlıdır.
Null Kontrolü Dahil:
Null karakterin kontrolü ve kopyalanması otomatik olarak halledilir.
Genel Notlar:
Bu tür kodlar, C dilinin minimalist ve düşük seviyeli doğasını temsil eder. Kodu anlamak biraz zor olsa da, C'de bu tarz yaklaşımlar hem sık kullanılır hem de yazılım geliştiricilere güçlü araçlar sunar. 😊
