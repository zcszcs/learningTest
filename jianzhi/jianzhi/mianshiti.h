#ifndef MIANSHITI_H_INCLUDED
#define MIANSHITI_H_INCLUDED
#include <string>//swap, <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <exception>
using namespace std;

/**
    注：此类名首字母都没有大写
**/
namespace jzOffer{

    struct listNode{
        int val;
        listNode* pNext;
    };

    struct binaryTreeNode{
        int val;
        binaryTreeNode* pLeft;
        binaryTreeNode* pRight;
    };

    struct ComplexListNode{
        int val;
        ComplexListNode* pNext;
        ComplexListNode* pSibling;
    };

    class Ti30{
        public:
            void getSmallestNums(int* nums, int low, int high, int n, int(*func)(int*, int, int));
        private:
            int Partition(int* nums, int low, int high, int(*func)(int*, int, int));
            void getSmallestNums_(int* nums, int low, int high, int n,int(*func)(int*, int, int));
            //int getPivot(int* nums, int low, int high);
    };

    class Ti29{
        public:
            int moreThanHalfNum(int * nums, int len);
    };

    class Ti28{
        public:
            void charPermutation(char* str, int len);
        private:
            void charPermutation_(char* str, int len, char* & isDup, int pLen);
    };

    class Ti27{
        public:
            binaryTreeNode* bstToDoubleList(binaryTreeNode* tree);
        private:
            binaryTreeNode* bstToDoubleListRight(binaryTreeNode* tree);
            void exchange(binaryTreeNode* a, binaryTreeNode* b);
    };

    class Ti26{
        public:
           ComplexListNode* clone(ComplexListNode* pHead);
        private:
            bool isContain(vector<pair<ComplexListNode*, ComplexListNode*>>& nodes, ComplexListNode* oldNode, ComplexListNode** newNode);
    };

    class ti25{
        public:
            bool findPath(binaryTreeNode* tree, int scroe);
        private:
            bool findPath_(binaryTreeNode* tree, int scroe, vector<int>& path);
    };

    class ti23{
        public:
            void printBSTFromUpToDown(binaryTreeNode* tree);
    };

    template<typename T>
    class ti21{
        public:
            T topAndPop(){
                if(sta.empty()){
                    printf("Empty stack!");
                    return NULL;
                }
                T res=sta.top();
                sta.pop();
                staMin.pop();
                return res;
            }

            void push(T t){
                sta.push(t);
                if(staMin.empty() || t<staMin.top())
                    staMin.push(t);
                else
                    staMin.push(staMin.top());
            }

            T minT(){
                if(staMin.empty()){
                    printf("Empty stack!");
                    return NULL;
                }
                return staMin.top();
            }
        private:
            stack<T> sta;
            stack<T> staMin;
    };

    class ti20{};

    class ti19{
        public:
            binaryTreeNode* getBinaryTreeImage(binaryTreeNode* tree);
    };

    class ti18{
        public:
            bool isChildTree(binaryTreeNode* tree, binaryTreeNode* cTree);
        private:
            bool isChildTree_(binaryTreeNode* tree, binaryTreeNode* cTree);
    };

    class ti17{
        public:
            listNode* mergeSortedList(listNode** pList1, listNode** pList2);
            listNode* mergeSortedListV1(listNode* pList1, listNode* pList2);
    };

    class ti16{
        public:
            listNode* rotateList(listNode* pList);
            listNode* rotateListV1(listNode* pList);
        private:
            listNode* rotateList_(listNode* pList, listNode** pTail);
    };

    class ti15{
        public:
            listNode* getTheLastKthNode(listNode** pList, int k);
    };

    class ti14{
        public:
            void adjustArrayToApartOdd(int* arr, int len);
    };

    class ti13{
        public:
            void deleteNode(jzOffer::listNode** pListHead, jzOffer::listNode* pToBeDeleted);
    };

    class ti12{
        private:
            inline void addOne(char* a, int& len, bool& isCon);
        public:
            int print1ToMaxN(int n);
    };

    class ti11{
        private:
            bool equa(int a, int b);
            double curPower(double base, int exponent);
        public:
            bool isValidInput;
            double power(double base, int exponent);
    };

    class ti10{
        public:
            int numberOfOne(int n);
    };

    class ti8{
        public:
            int minZ(int* arr, int low, int high);
    };


    template<typename T>
    class ti7{
    /**
    两个栈实现队列
    queue: push, front, pop, empty, size
    stack: push, top, pop, empty, size
    **/
        public:
            void pushTail(const T& node){
                stk1.push(node);
            }

            T popHead(){
                T node;
                if(stk2.empty()){
                    while(!stk1.empty()){
                        node=stk1.top();
                        stk2.push(node);
                        stk1.pop();
                    }
                }
                if(stk2.empty())
                    throw new exception;
                node=stk2.top(), stk2.pop();
                return node;
            }
        private:
            stack<T> stk1;
            stack<T> stk2;
    };
    template<typename T>
    class ti7_{
    /**
    两个栈实现队列
    **/
        public:
            void push(const T& node){
                que1.push(node);
            }

            T topAndPop(){
                T node;
                if(que2.empty()){
                    swapQueue();
                }
                if(que2.empty())
                    throw new exception;
                node=que2.front(), que2.pop();
                return node;
            }
        private:
            void swapQueue(){
                if(que1.empty())
                    return;
                T node=que1.front();
                que1.pop();
                swapQueue();
                que2.push(node);
            }
            queue<T> que1;
            queue<T> que2;
    };

    class ti6{
        private:
            int isFind(int*, int*, int);
        public:
            struct bstNode{
                int val;
                bstNode* pL;
                bstNode* pR;
            };
            ti6::bstNode* constructBst(int* preOrder, int* inOrder, int len);
    };

    class ti3{
        public:
            void test();
            bool find2DElement(int**, int, int, int);
    };
    class ti35{
        public:
            //char findFirstChar(char* str, unsigned int len);
            //c_str没有string好用
            char findFirstChar(string str);

    };


}

namespace wdBaoDian{
    class ti257{
        public:
            void findSmallK();
        private:
            vector<int>::iterator findMax(vector<int>&);
    };
}


#endif // MIANSHITI_H_INCLUDED
