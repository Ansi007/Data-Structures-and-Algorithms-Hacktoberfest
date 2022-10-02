public class BubbleSort {
    private final int[] items = {24, 32, 2, 2, 18, 10};

    public static void main(String[] args) {
        var bubbleSort = new BubbleSort();
        var sortedArray = bubbleSort.sortAscending(bubbleSort.items);

        for (int i=0; i < sortedArray.length; i++) {
            System.out.println(sortedArray[i] + " ");
        }
    }

    private int[] sortAscending(int[] list) {
        int temp;

        for (int i = 0; i <= list.length - 2; i++) {
            for (int j = 0; j <= list.length - 2; j++) {
               if (list[j] > list[j + 1]) {
                  temp = list[j + 1];
                  list[j + 1] = list[j];
                  list[j] = temp;
               }
            }
        }

        return list;
    }
}
