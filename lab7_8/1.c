#include<stdio.h>
#include<stdlib.h>
#define pf printf
#define sf scanf

int mutex=1,full=0,empty=5,x=0;

int signal(int val)
{
    return ++val;
}
int wait(int val)
{
    return --val;
}
void consumer()
{
    mutex=wait(mutex);
    empty=signal(empty);
    full=wait(full);
    pf("consumer consumes %d item\n",x);
    x--;
    mutex=signal(mutex);

}

void producer()
{

    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    pf("producer produces %d item\n",x);
    mutex=signal(mutex);


}

int main()
{
    
    while(1)
    {
    int op;

    pf("1. producer \n 2. consumer \n 3. exit ");
    sf("%d",&op);

    switch(op)
    {
        case 1:
                    if(empty!=0 && mutex)
                    {
                        producer();
                    }
                    else
                    {
                        pf("buffer is full");
                    }
                    break;
         case 2:
                    if(full!=0 && mutex)
                    {
                        consumer();
                    }
                    else
                    {
                        pf("buffer is empty");
                    }
                    break; 
        case 3: exit(0); break;

        
    }
        
    }

    
        return 0;



}


