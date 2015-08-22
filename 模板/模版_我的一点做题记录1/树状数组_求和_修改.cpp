int get_sum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += tree[i];
        i -= (i&-i);
    }
    return sum;
}

void modify(int i,int a)    //将第i个元素加a
{
    while(i <= mx)
    {
        tree[i] += a;
        i += (i&-i);
    }
    return;
}
