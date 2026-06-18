func lengthOfLongestSubstring(s string) int {
    maxLength := 0
    left := 0
    mp := map[rune]bool{}
    for right, c := range s {
        seen, found := mp[c]
        if(!found){
            mp[c] = true
            maxLength = max(maxLength, (right-left+1))
        } else if found && seen {
            for rune(s[left]) != c {
                mp[rune(s[left])] = false
                left++
            }
            left++
        } else if found && !seen {
            mp[c] = true
            maxLength = max(maxLength, (right-left+1))
        }
    }
    return maxLength
}
