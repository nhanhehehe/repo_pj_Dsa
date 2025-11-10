#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define ll long long
#include <iomanip>
using namespace std;

vector<string> idArchieve; // luu tru ma nhan vien 

struct employee
{
   string id;
   string name;
   string position;
   int year;
   int manager;
};

struct Node
{
   int data1;
   employee data;
   Node *next;
   vector<Node *> children;
};

Node *createNode(employee nv)
{
   Node *temp = new Node;
   temp->data = nv;
   temp->next = NULL;
   return temp;
}

struct List
{
   Node *first;
   Node *last;
};

void createList(List &l)
{
   l.first = NULL;
   l.last = NULL;
}

// tao nhan vien ( employee date cua Node)
employee createEmployee()
{
   employee nv;
   cout << "=== Nhap thong tin nhan vien moi ===\n";
   cout << "Nhap ma id: ";
   string id;
   cin >> id;
   nv.id = id;
   cout << "Nhap ten: ";
   string name;
   cin.ignore();
   getline(cin, name);
   nv.name = name;
   cout << "Nhap vi tri: ";
   string pos;
   cin >> pos;
   nv.position = pos;
   cout << "Nhap nam lam viec: ";
   int y;
   cin >> y;
   nv.year = y;
   cout << "Nhap ma quan ly: ";
   int ma;
   cin >> ma;
   nv.manager = ma;
   cout << endl << endl;
   return nv;
}

// them node vao sau
void InsertNode(List &l)
{
   Node *nv = createNode(createEmployee());

   if (l.first == NULL)
   {
      l.first = nv;
      l.last = nv;
   }
   else
   {
      l.last->next = nv;
      l.last = nv;
   }
}




// ============================ chuc nang 1 ============================

// tim nhan vien ban id
Node *SearchID(Node *root, string id)
{
   if (root == NULL)
      return NULL;
   if (root->data.id == id)
      return root;

   for (Node *child : root->children)
   {
      Node *found = SearchID(child, id);
      if (found)
         return found;
   }
   return NULL;
}

// them moi nhan vien
void InsertEmployee(Node *root, employee nv)
{
   Node *add = SearchID(root, nv.id);
   if (add == NULL)
   {
      return;
   }

   Node *newEmployee = createNode(nv);
   add->children.push_back(newEmployee);
   cout << "Them nhan vien thanh cong! " << endl << endl;
}

//chuc nang 1
void Function1(List& l) {
   employee newEmployee = createEmployee();
   InsertEmployee(l.first, newEmployee);
}


// ============================================================

// Node* Hash_table[11];

// int hashing(int data) {
//    return data % 11;
// }

// void insert(int data)  {
//    int index = hashing(data);
//    Node* temp = new Node;
//    temp->data = data;
//    if (Hash_table[index] == NULL) {
//       Hash_table[index] = temp;
//       return;
//    }
//    temp->next = Hash_table[index];
//    Hash_table[index] = temp;
// }

// int find(int data) {
//    int index = hashing(data);
//    Node *curr = Hash_table[index];
//    while (curr!= NULL) {
//       if (curr->data == data) return 1;
//       curr = curr->next;
//    }
//    return 0;
// }

// menu chuc nang
void Menu(List& l)
{
   List p = l;
   cout << "-------------------------------------------------------------------------------------------------------------\n";
   cout << right << setw(70) << "=====  QUAN LY TO CHUC DOANH NGHIEP  =====\n";
   cout << "1. Them nhan vien\n";
   cout << "2. Xoa nhan vien\n";
   cout << "3. Cap nhat thong tin nhan vien\n";
   cout << "4. Hien thi so do to chuc\n";
   cout << "5. Tim nhan vien theo ID\n";
   cout << "6. Tim nhan vien theo Ten\n";
   cout << "7. Luu du lieu ra file\n";
   cout << "8. Tai du lieu tu file\n";
   cout << "0. Thoat\n";
   cout << "-------------------------------------------------------------------------------------------------------------\n";
   cout << "Nhap lua chon: ";
   int t;
   while (true)
   {
      cin >> t;
      if (t == 0)
      {
         cout << "Thoat chuong trinh ...";
         return;
      }
      if (t == 1)
      {
         Function1(p);
         break;
      }
      if (t == 2)
      {
         break;
      }
      if (t == 3)
      {
         break;
      }
      if (t == 4)
      {
         break;
      }
      if (t == 5)
      {
         break;
      }
      if (t == 6)
      {
         break;
      }
      if (t == 7)
      {
         break;
      }
      if (t == 8)
      {
         break;
      }
      else
      {
         cout << "!lua chon khong hop le!\n";
         cout << "vui long chon lai: ";
      }
   }
}

void printOrg(Node *root, int level = 0)
{

   if (root == nullptr)
      return;
   // cout << "-------------------------------------------------------------------------------------------------------------\n";
   // cout << right << setw(80) << "===== CAU TRUC DOANH NGHIEP  =====\n\n";
   // In thụt đầu dòng theo cấp bậc
   for (int i = 0; i < level; i++)
      cout << '\t';

   cout << "- " << root->data.id << " | " << root->data.name << " | " << root->data.position << " | " << root->data.year << " | " << root->data.manager << endl;

   for (auto child : root->children)
   {
      printOrg(child, level + 1);
   }
   // cout << "-------------------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
   cout << "HI\n";
   cout << "test";
   return 0;
}