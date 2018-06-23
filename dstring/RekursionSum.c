#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int sum(int tal)
{
  int res;
  if (tal<=0)
  return 0;
  printf("sum(%d) anropas\n",tal);
  res=tal+sum(tal-1);
  printf("sum(%d) returerar %d \n",tal,res);
  return res;
}
int main()
{
    int tal,result;
    scanf("%d",&tal);
    result = sum(tal);
    printf("Result: %d\n",result);
    /*assert(sum(1) == 1);
    assert(sum(2) == 3);
    assert(sum(3) == 6);
    assert(sum(4) == 10);
    assert(sum(5) == 15);
    assert(sum(20) == 210);
    assert(sum(0) == 0);
    assert(sum(-1) == 0);*/


}
