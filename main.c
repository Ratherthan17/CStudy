#include <stdio.h>
#include <stdlib.h>




//预处理print加分号
#define print printf("没加分号。\n")
#define print2 printf("加了分号.\n");

int main1()
{
    printf("Hello world!\n");

    print;
    print2;
    return 0;
}

//函数参数是表达式---会先求实参的值，再传给形参
int Square(int num1)
{
    return num1*num1;
}
int main2()
{
    int result = Square(2);

    printf("result = %d \n",result);

    result = Square(2+1);

    printf("result = %d \n",result);

    return 0;
}

//printf中间有多个字符串
int main3()
{
    printf("hello ""world"" ------- "" ************ ");

    return 0;
}



//三目运算符简单运算，不加括号————>可以，没问题
int Max(int num1,int num2)
{
    return num1 > num2 ? num1:num2;
}
int main4()
{

    int a = 1;
    int b = 2;
    int c = Max(a,b);

    printf("c = %d\n",c);

    return 0;
}


//#undef 的位置
#define M 100
void Undefine();

int main5()
{
    printf("%d\n",M);

    Undefine();
    // #undef M
    printf("%d\n",M);  //会正常打印

    //printf("%d\n",M);

    return 0;
}

void Undefine()
{
#undef M
    printf("Undefine\n");
}

//命令参数定义
/*int main6()
{
    int arr[num];
    int i=0;
    for(i=0;i<num;i++)
    {
        arr[i] = i;
    }

    for(i=0;i<num;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }

    getchar();

    return 0;
}
*/



//结构体占多少字节————>是最大变量类型的整数倍
struct A
{
    char c1;
    int i;
    char c2;
};

struct B
{
    char c1;
    char c2;
    int i;
};


struct C
{
    int i;
    char c1;
    char c2;
};

int main7()
{
    struct A a;
    struct B b;
    struct C c;

    printf("ths size of a is %d\n",sizeof(a));//占12字节
    printf("ths size of b is %d\n",sizeof(b));//占8字节
    printf("ths size of c is %d\n",sizeof(c));//占8字节，最大类型的整数倍，所以是8不是6

    //char c1 = (char)6;//不行
    char c1 = '6';
    printf("c : %c\n",c1);

    return 0;
}


//指针赋为0和赋为NULL一样吗？——Yes
int main8()
{
    int *p = 0;

    if(p == NULL)
    {
        printf("p == null\n");
        printf("p == %p\n",p);

    }
    else
    {
        printf("p == %p\n",p);
    }

    *p = 1;

    return 0;
}


//获取字符串的长度

int GetStrLenth(char* string)
{
    int lenth = 0;

    while(*(string++) != '\0')
    {

        lenth++;
    }

    return lenth;
}


int main()
{
    char* str = "hello";

    printf("the size of str is : %d\n",sizeof(str));//结果为8，64位下的指针变量所占字节
    printf("the size of str is : %d\n",sizeof(*str));//结果为1，为str[0]的大小

    printf("the size of str is : %d\n",strlen(str));
    printf("the size of str is : %d\n",GetStrLenth(str));

    return 0;
}


/*-------------------- ⬇ Leetcode 题 ⬇ ------------------*/

//两数相加
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0, j = 0;
    //returnSize = (int*)malloc(2 * sizeof(int));

    for (i = 0; i < numsSize - 1; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                returnSize[0] = i;
                returnSize[1] = j;

            }
        }
    }
    return returnSize;
}


int main9()
{

    int numsSize=0,target = 0;

    int *nums = (int *)malloc(sizeof(int)*2);

    if(nums == NULL)
    {
        //printf(errno_t)
        return 1;
    }
    else
    {
        nums[0] = 0;
        nums[1] = 1;
    }

    printf("p[0] = %d\n",nums[0]);
    printf("p[1] = %d\n",nums[1]);


    return 0;
}



//回文


int GetLenth(int x)
{
    int lenth = 1;

    if(x < 0)
        x = -x;

    while(x/10 > 0)
    {
        lenth++;
        x = x/10;
    }

    return lenth;
}

int main10()
{
    int x;
    printf("input a num : ");
    scanf("%d",&x);

    int lenth = GetLenth(x);
    printf("the lenth of x is : %d\n",lenth);

    //用来存储 x 字符串
    char* strX = (char*)malloc((lenth+1) * sizeof(char));

    sprintf(strX,"%d",x);

    if(strX[lenth] == '\0')
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    char* right;
    char* left = &strX[0];
    //bool isHui;
    for(right = &strX[lenth]; right > left; left++)
    {
        right--;

        if(*right != *left)
        {
            printf("it is not a hui\n");
        }
        printf("left : %c\n",*left);
        printf("right: %c\n",*right);


    }


    return 0;
}


/*-------------------- ⬆ Leetcode 题 ⬆ ------------------*/
