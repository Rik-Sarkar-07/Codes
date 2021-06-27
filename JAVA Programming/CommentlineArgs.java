class CommentlineArgs {
    public static void main(String[] args) {
      
        int arr[] = new int[args.length];

        for(int i=0;i<args.length;i++)
        {
            arr[i] = Integer.parseInt(args[i]);
        }

        int n = args.length;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        System.out.println("Min Element = "+arr[0]);
        System.out.println("Max Element = "+arr[n-1]);
    }
}
