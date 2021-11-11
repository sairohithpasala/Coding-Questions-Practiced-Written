public class MaximizePoint {

    public static void main(String[] args) {
        int[] arr = {4,5,8, 7};
        System.out.println(pirntMaxm(arr, 0));
    }

    static int pirntMaxm(int arr[], int points) {
        //declaring  tempMaxPoint 
        int tempMaxPoint = points;
        //declaring maxmTill now which sotre the maxm pints in this functioncall.
        int maxmTillNow = points;
        //iterating through the given array elements
        for (int cur : arr) {
            //cheching if it is not 0, if not 0 then add the current value to tempMaxPoint
            if (cur != 0) {
                //creating a new temp array , so that the original array given to us does not change
                int[] temp = new int[arr.length];
                for (int i = 0; i < arr.length; i++)
                    temp[i] = arr[i];


                //iterate from temp array and check if equal element is found. if yes then add to tempMaxPoint amd make that element 0.
                for (int i = 0; i < temp.length; i++) {
                    if (temp[i] == cur) {
                        tempMaxPoint += cur;
                        temp[i] = 0;
                    } 
                    // make (cur - 1) and (cur+1) to 0
                    else if (temp[i] == (cur - 1) || temp[i] == (cur + 1)) {
                        temp[i] = 0;
                    }
                }
                //call the printMaxm funtion again with temp array, and current tempMaxPoint
                tempMaxPoint = pirntMaxm(temp, tempMaxPoint);
                //compare with maxmTillNow, if greater then update
                if (tempMaxPoint > maxmTillNow) {
                    maxmTillNow = tempMaxPoint;

                }
                tempMaxPoint = points;
            }
        }
        //return the maxm points,  of this function call
        return maxmTillNow;
    }
}