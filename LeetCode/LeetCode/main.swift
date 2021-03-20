//
//  main.swift
//  LeetCode
//
//  Created by Private Privacy on 20/03/2021.
//

import Foundation

class Solution {
    func distributeCandies(candyType: [Int]) -> Int {
        var differentTypes = 0
        var prevType = -1
        
        for candy in candyType.sorted(){
            if(candy != prevType)
            {
                differentTypes+=1
                prevType = candy
            }
        }
        
        if(candyType.count/2 < differentTypes)
        {
            return candyType.count/2
        }
        else
        {
            return differentTypes
        }
    }
}

var sol:Solution = Solution()

print(sol.distributeCandies(candyType: [1,2,3,3,3,3]))
