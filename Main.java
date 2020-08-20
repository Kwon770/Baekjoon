// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// Scanner sc = new Scanner(System.in);
// Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
// StringBuilder sb = new StringBuilder();

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] pibo = new int[21];
        pibo[1] = 1;
        pibo[2] = 1;
        pibo[3] = 2;

        int n = Integer.parseInt(br.readLine());
        for (int i = 4; i <= n; i++) {
            pibo[i] = pibo[i - 1] + pibo[i - 2];
        }

        System.out.println(pibo[n]);
    }

    static int[] parseIntArr(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }
}
