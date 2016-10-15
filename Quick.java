import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Quick
{
    private static final int MAX_INT = 10;
    
    public static int partition(int[] a, int lo, int hi)
    {
        int i = lo, j = hi + 1;
        while (true)
        {
            while (a[++i] < a[lo])
                if (i == hi) break;
            
            while (a[--j] > a[lo])
                if (j == lo) break;
            
            if (i >= j) break;               
            swap(a, i, j);
        }
        swap(a, lo, j);
        return j;
    }
    
    public static void sort(int[] a, int lo, int hi)
    {
        if (hi <= lo) return;
        int j = partition(a, lo, hi);
        sort(a, lo, j - 1);
        sort(a, j + 1, hi);
    }
        
    public static void sort(int[] a)
    {
        StdRandom.shuffle(a);
        sort(a, 0, a.length - 1);
    }
            
    public static void main(String[] args)
    {
        int[] a = fillRandomly(25);
        sort(a);
        StdOut.println(isSorted(a));
        printArray(a);
    }
    
    public static void swap(int[] a, int i, int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    public static int[] fillRandomly(int sz)
    {
        int[] temparr = new int[sz];
        for (int i = 0; i < sz; i++)
            temparr[i] = StdRandom.uniform(-MAX_INT, MAX_INT);
        return temparr;
    }
    
    public static boolean isSorted(int[] a)
    {
        int N = a.length;
        for (int i = 1; i < N; i++)
            if (a[i] < a[i - 1]) return false;
        return true;
    }
    
    public static void printArray(int[] a)
    {
        int N = a.length;
        for (int i = 0; i < N; i++)
            StdOut.print(a[i] + " ");
        StdOut.println();
    }
}
