int prostopadloscian(int a, int b, int c)
{
    return 2 * a * b + 2 * a * c + 2 * c * b;
}

int pitagoras(int x, int y, int z)
{
    if ((x * x) + (y * y) == (z * z))
        return true;
    else
        return false;
}
