// https://www.acmicpc.net/problem/14681
// IF문(4), 사분면고르기
// NUMBER 14681

import java.io.BufferedReader;
// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.Scanner;
// Scanner scanner = new Scanner(System.in);

public class Main {
    public static void main(String[] args) {
        TreeSet<Integer> bugers = new TreeSet<>();
        TreeSet<Integer> drinks = new TreeSet<>();

        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            bugers.add(scanner.nextInt());
        }
        for (int i = 0; i < 2; i++) {
            drinks.add(scanner.nextInt());
        }
        System.out.println(bugers.first() + drinks.first() - 50);
        scanner.close();
    }
}
