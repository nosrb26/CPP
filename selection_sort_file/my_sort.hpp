// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful
template <class T>
void swap(T &a, T &b)
{
    T c(std::move(a));
    a = std::move(b);
    b = std::move(c);
}
template <class T, size_t N>
void swap(T (&a)[N], T (&b)[N])
{
    for (size_t i = 0; i < N; ++i)
        swap(a[i], b[i]);
}

template <class T>
void my_selection_sort(T begin, T end)
{
    end--;
    while (begin != end)
    {
        T max = begin;
        for (T st = begin; st != end; st++)
            if (*max < *st)
                max = st;
        if (*max > *end)
            swap(*max, *end);
        end--;
    }
}