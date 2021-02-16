typedef关键字与结构体、结构体指针的定义:
一、使用typedef定义结构体
typedef用来定义新的数据类型，通常typedef与结构体的定义配合使用。使用typedef的目的使结构体的表达更加简练（所以说typedef语句并不是必须使用的）。

定义一个名字为TreeNode的结构体类型（现在并没有定义结构体变量，并不占用内存空间）：
struct TreeNode
{
        int Element;
        struct TreeNode* LeftChild;
        struct TreeNode* RightChild;
};

结构体起一个别名Node，这时Node就等价于struct TreeNode
typedef struct TreeNode Node;

将结构体的定义和typedef语句可以连在一起写：
typedef struct TreeNode
{
        int Element;
        struct TreeNode* LeftChild;
        struct TreeNode* RightChild;
}Node;

二、使用typedef定义结构体指针
定义一个名为TreeNode的结构体，和指向该结构体类型的指针PtrToTreeNode（不使用typedef）：
struct TreeNode
{
        int Element;
        struct TreeNode* LeftChild;
        struct TreeNode* RightChild;
};
struct TreeNode *PtrToTreeNode； //定义指针

使用typedef关键字用一个单词Node代替struct TreeNode，并定于指向该结构体类型的指针PtrToTreeNode：
struct TreeNode
{
        int Element;
        struct TreeNode* LeftChild;
        struct TreeNode* RightChild;
};
typedef struct TreeNode Node;   //用Node代替struct TreeNode
Node *PtrToTreeNode;            //定义指针

将结构体的定义和typedef连在一起写，再次缩短代码：
typedef struct TreeNode
{
        int Element;
        struct TreeNode* LeftChild;
        struct TreeNode* RightChild;
}Node;                          //定义结构体并用Node代替struct TreeNode
Node *PtrToTreeNode;            //定义指针

还可以继续缩短代码，直接定义了指向结构体类型的指针，但是这种写法没有为结构体起一个别名。
typedef struct TreeNode
{
        int Element;
        struct TreeNode* LeftChild;
        struct TreeNode* RightChild;
} *PtrToTreeNode;               //直接定义指针