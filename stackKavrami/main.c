#include <stdio.h>
#include <stdlib.h>
/*tek tarafli lifo
ilk giren deger en son çıkar mantığı ile çalışan yapıdır .*/
typedef struct n{
int data;
struct n * next;
}node;

// Ekleme işlemini gerçekleştirdiğim fonksiyon
node * push(node * stack,int data){
if(stack == NULL){ // eğer stack boş ise oluşturuyorum
    stack = (node *)malloc(sizeof(node));
    stack->data = data;
    stack->next = NULL;
    return stack;
}
//eğer stack yapımn boş değilse ve ekleme yapılıyor ise
else{
    //temp degeri oluşturuyorum içerisine parametre olarak gelen degeri ekliyorum
    node * temp = (node *)malloc(sizeof(node));
    temp->data = data;
    // temp degerimin nexti parametre oalrak gelen stack yapım oluyor
    temp->next = stack;
    // geriye temp degerimi döndürüyorum
    return temp;

    /*bu sayede stack yapımın içerisine degerler eklediğim zaman sırasıyla 10,20,30 degerlerini eklemiş olayım
    ilk önce stack boştu oluşturuldu ve 10 degeri eklendi
    20 degeri eklendiği zaman 20 degerini tutacak olan bir temp oluşturuldu ve 20 -> 10 olacak şekilde pointerlar ayarlandı geriye 20 döndürüldü
    30 degerini eklediğim zaman 30 -> 20 -> 10 şeklinede oldu*/
}
}
//Stack yapımdan degerleri tek tek sileceğim fonksiyon
node * pop(node * stack){
    // silinen degeri yazdırıyorum  10 20 30 eklenmiş olan bir durumda listemin en başında en son giren değer olan 30 bulunduğuı için ilk başta 30 yazıyor
printf("\n %d ",stack->data);
//temp adında bir pointer oluşturuyorum ve stack adlı yapımın bir sonraki değerini gösteriyorum
node * temp = stack->next;
//stack adlı pointerimin işaret ettiği bölümü boşaltıyorum
free(stack);
//geriye temp değerimi(stack->next) döndrüyorum bu sayede en son giren değer ilk çıkmış oluyor
return temp;
}
void yazdir(node * stack){
node * iter = stack;
while(iter->next != NULL){
    printf(" %d ",iter->data);
    iter = iter->next;
}
printf(" %d ",iter->data);
}
int main()
{
   node * stack = NULL;
    stack = push(stack,10);
    stack = push(stack,20);
    stack = push(stack,30);
    stack = push(stack,40);
    yazdir(stack);
   stack =  pop(stack);
   stack =  pop(stack);
   printf("\n");
   yazdir(stack);
    return 0;
}
