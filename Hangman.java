import java.util.*;

public class HangmanGame {

    static ArrayList<String> words = new ArrayList<String>();

    static void printHangman(int state) {
        if (state == 0) {
            System.out.println("You are still alive");
        } 
        else if (state == 1) {
            System.out.println("4 takes to go..");
            System.out.println("   |   ");
            System.out.println("   O   ");
            System.out.println("   |   ");
        } 
        else if (state == 2) {
            System.out.println("3 takes to go..");
            System.out.println("   |   ");
            System.out.println("   O   ");
            System.out.println("  \\\\   ");
            System.out.println("   |   ");
        } 
        else if (state == 3) {
            System.out.println("2 takes to go..");
            System.out.println("   |   ");
            System.out.println("   O   ");
            System.out.println(" \\\\ // ");
            System.out.println("   |   ");
        } 
        else if (state == 4) {
            System.out.println("1 takes to go..");
            System.out.println("   |   ");
            System.out.println("   O   ");
            System.out.println(" \\\\ // ");
            System.out.println("   |   ");
            System.out.println(" //    ");
        } 
        else if (state == 5) {
            System.out.println("You lost..");
            System.out.println("   |   ");
            System.out.println("   O   ");
            System.out.println(" \\\\ // ");
            System.out.println("   |   ");
            System.out.println(" // \\\\ ");
        }
    }

    static String giveWord() {
        Random rand = new Random();
        int index = rand.nextInt(words.size());
        return words.get(index);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        words.add("steveharrington");

        int state = 0;
        String wordToPredict = giveWord();
        String wordPredictedTillNow = "";

        int currentIndex = 0;

        while (state < 5 && !wordToPredict.equals(wordPredictedTillNow)) {
            System.out.println("Guess an alphabet dude!");
            char ch = sc.next().charAt(0);

            if (ch == wordToPredict.charAt(currentIndex)) {
                wordPredictedTillNow += ch;
            } else {
                state = state + 1;
                printHangman(state);
            }

            currentIndex = currentIndex + 1;
        }

        if (wordToPredict.equals(wordPredictedTillNow)) {
            System.out.println("You got it Dude!");
        }

        if (!wordToPredict.equals(wordPredictedTillNow) && state == 5) {
            System.out.println(wordToPredict);
        }

        sc.close();
    }
}
