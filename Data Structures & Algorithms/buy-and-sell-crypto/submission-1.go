func maxProfit(prices []int) int {
    minSell := math.MaxInt64
    maxProfit := 0

    for _, v := range prices{
        if v < minSell {
            minSell = v
        }
        profit := v-minSell
        maxProfit = max(maxProfit, profit)
    }
    return maxProfit
}
