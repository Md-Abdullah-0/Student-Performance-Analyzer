#include<stdio.h>
#include<string.h>
char fav(int total);
struct student
{
    char name[100],dep[100],id[100],grade;
    int mid,final,total;

};
int main()
{
   int n;
   scanf("%d",&n);getchar();
   struct student p[n];
 for(int i=0;i<n;i++)
   {
       fgets(p[i].name,100,stdin);
       p[i].name[strcspn(p[i].name,"\n")]='\0';

       fgets(p[i].id,100,stdin);
       p[i].id[strcspn(p[i].id,"\n")]='\0';
       int idlen=strlen(p[i].id);

       fgets(p[i].dep,100,stdin);
       p[i].dep[strcspn(p[i].dep,"\n")]='\0';

       scanf("%d",&p[i].mid);
       scanf("%d",&p[i].final);getchar();
       
   }
   printf("\n");
   int s=0,h=0,f=0;


   for(int i=0;i<n;i++)
   {
    printf("\n");
      printf("Student %d\n",i+1);
      if(strncmp(p[i].id,"2026",4)==0) 
       {
           printf("Current Year Student\n");
       }
      if(strlen(p[i].name)>15)
      {
        printf("Long Name Detected\n");
      }
        printf("Name: %s\n",p[i].name);
      
    
      printf("ID: %s\n",p[i].id);
      printf("Department: %s\n",p[i].dep);

      p[i].total=p[i].mid+p[i].final;
      int idlen=strlen(p[i].id);
      int bo=p[i].id[idlen-1]-'0';
      if(strstr(p[i].dep, "Engineering") != NULL)
        {
            p[i].total=p[i].total+bo;
        }
        printf("Final Total: %d\n",p[i].total);





        p[i].grade=fav(p[i].total);
        printf("Grade: %c\n",fav(p[i].total));
        

      
        s+=p[i].total;


        if(i==0 || p[i].total>h)
        {
            h=p[i].total;

        }
        if(p[i].grade=='F')
        {
             f++;
        }
        




    }
    printf("\n");
    printf("Highest Scorer: ");
    for(int i=0;i<n;i++)
    {
        if(p[i].total==h)
        {
            printf("%s ",p[i].name);
        }
    }printf("\n");
    double avg=(double)s/n;
    printf("Average Final Total: %.2lf\n",avg);
    printf("Total Failed Students: %d\n",f);

    



return 0;
 }
char fav(int total)
    {
        if(total>=80)
        return 'A';
        else if(total>=70)
        return 'B';
        else if(total>=60)
        return 'C';
        else if(total>=50)
        return 'D';
        else
        return 'F';

    }


