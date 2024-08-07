class Program
    {
        static void Main(string[] args)
        {
            int[] inputArray = new int[9];
            int maxValue = 0;
            int maxIndex = 0;

            for (int i = 0; i < 9; i++)
            {
                int value = int.Parse(Console.ReadLine());
                inputArray[i] = value;

                if (value > maxValue)
                {
                    maxValue = value;
                    maxIndex = i;
                }
            }

            Console.WriteLine(maxValue);
            Console.WriteLine(maxIndex+1);
        }
    }