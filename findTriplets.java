import java.util.*;

// import javax.lang.model.util.ElementScanner6;

public class findTriplets {
    public static int findTripletsInArray(int[] arr) {
        int counter = 0;
        if (arr.length <= 2) {
            return 0;
        }
        int i = arr.length - 1;
        while (i >= 2) {
            int r = i - 1;
            int l = 0;
            while (l < r) {
                int s = arr[l] + arr[r];
                if (s == arr[i]) {
                    counter++;
                    l++;
                    r--;
                } else if (s < arr[i]) {
                    l++;
                } else {
                    r--;
                }
            }
            i--;
        }
        return counter;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        System.out.println("Sorted Array is given below");
        for (int i : arr) {
            System.out.print(i+" ");
        }
        System.out.println();
        System.out.println("Total triplets in the array is " + findTripletsInArray(arr));
        System.out.println();
    }
}
/*
 * abstract 6 1 3 5 2 4 7 Total triplets in the array is 5
 */