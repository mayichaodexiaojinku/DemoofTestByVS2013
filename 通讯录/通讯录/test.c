#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person{
	char name[20];
	char phone[12];
	char gender[5];
	char address[20];
	unsigned int age;
	struct person *next;
};
int menu()
{
	printf("----------欢迎进入通讯录系统------------\n");
	printf("|      1.添加           2.删除         |\n");
	printf("|      3.查找           4.修改         |\n");
	printf("|      5.显示           6.清空         |\n");
	printf("|      7.排序           0.退出         |\n");
	printf("----------------------------------------\n");
	printf("请选择-->");
	int choose;
	scanf("%d", &choose);
	return choose;
}
void insert(struct person **ph)
{
	struct person *p = malloc(sizeof(struct person));
	printf("name:");
	scanf("%s", p->name);
	printf("phone:");
	scanf("%s", p->phone);
	printf("gender:");
	scanf("%s", p->gender);
	printf("address:");
	scanf("%s", p->address);
	printf("age:");
	scanf("%s", &p->age);
	p->next = NULL;
	if (*ph == NULL)
		*ph = p;
	else
	{
		struct person *cur = *ph;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = p;
	}
}
void erase(struct person **ph)
{
	printf("请输入要删除的人：");
	char name[20];
	scanf("%s",name);
	struct person *pre = NULL;
	struct person *cur = *ph;
	while (cur != NULL)
	{
		if (strcmp(cur->name, name) == 0)
			break;
		pre = cur;
		cur = cur->next;
	}
	if (pre == NULL)
	{
		*ph = cur->next;
		free(cur);
	}
	else
	{
		if (cur != NULL)
		{
			pre->next = cur->next;
			free(cur);
		}
	}

}
void show(struct person *ph)
{
	while (ph != NULL)
	{
		printf("%s\n", ph->name);
		ph = ph->next;
	}
}
void find(struct person *ph)
{
	show(ph);
	printf("name：");
	char name[20];
	scanf("%s", name);
	struct person *cur = ph;
	while (cur != NULL)
	{
		if (strcmp(cur->name, name) == 0)
		{
			printf("%s %s \n", cur->name, cur->phone);
			break;
		}
		cur = cur->next;
	}
	if (cur == NULL)
	{
		printf("查无此人\n");
	}

}
void sort(struct person *ph)
{
	struct person *cur = ph;
	struct person *p = cur;
	while (cur != NULL)
	{
		p = cur;
		while (p != NULL)
		{
			if (p->age < cur->age)
			{
				char tmp1[20];
				strcpy(tmp1, p->name);
				strcpy(p->name, cur->name);
				strcpy(cur->name, tmp1);
				char tmp2[12];
				strcpy(tmp2, p->phone);
				strcpy(p->phone, cur->phone);
				strcpy(cur->phone, tmp2);
				char tmp3[12];
				strcpy(tmp3, p->gender);
				strcpy(p->gender, cur->gender);
				strcpy(cur->gender, tmp3);
				char tmp4[20];
				strcpy(tmp4, p->address);
				strcpy(p->address, cur->address);
				strcpy(cur->address, tmp4);
				int a=0;
				strcpy(a, p->age);
				strcpy(p->age, cur->age);
				strcpy(cur->age, a);

			}
			p = p->next;
		}
		cur = cur->next;
	}
}
void modify(struct person **ph)
{
	struct person *cur = *ph;
	printf("请输入要修改人的姓名：\n");
	char name[20];
	scanf("%s", &name);
	printf("请输入要修改的信息：\n");
	printf("name:");
	scanf("%s", cur->name);
	printf("phone:");
	scanf("%s", cur->phone);
	printf("gender:");
	scanf("%s", cur->gender);
	printf("address:");
	scanf("%s", cur->address);
	printf("age:");
	scanf("%s", &cur->age);
}
void clear(struct person *ph)
{
	struct person *p = ph;
	free(p);
	p = NULL;

}
int main()
{
	int choose;
	struct person *head = NULL;
	do
	{
		choose = menu();
		switch (choose)
		{
		case 1:
			insert(&head);
			break;
		case 2:
			erase(&head);
			break;
		case 3:
			find(head);
			break;
		case 4:
			modify(&head);
			break;
		case 5:
			show(head);
			break;
		case 6:
			clear(&head);
			break;
		case 7:
			sort(head);
			break;
		case 0:
			exit;
		}
	} while (choose);
	return 0;
}