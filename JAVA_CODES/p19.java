import java.io.*;

public class p19 {

    public static void writeSentencesToFile(String fileName, String[] sentences) {
        try (FileWriter writer = new FileWriter(fileName)) {
            for (String sentence : sentences) {
                writer.write(sentence + System.lineSeparator());
            }
            System.out.println("Sentences written to file successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred while writing to the file.");
            e.printStackTrace();
        }
    }
    public static void extractVowelsFromFile(String fileName) {
        String vowels = "AEIOUaeiou";
        StringBuilder vowelBuilder = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                for (char c : line.toCharArray()) {
                    if (vowels.indexOf(c) != -1) {
                        vowelBuilder.append(c);
                    }
                }
            }
            System.out.println("Vowels extracted from the file: " + vowelBuilder.toString());
        } catch (IOException e) {
            System.out.println("An error occurred while reading the file.");
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        String fileName = "sentences.txt";
        String[] sentences = {
            "My name is anshika sharma.",
            "I am 20 years old",
            "i live in dehradun",
            "Vowels will be extracted from these sentences."
        };
        writeSentencesToFile(fileName, sentences);
        extractVowelsFromFile(fileName);
    }
}

