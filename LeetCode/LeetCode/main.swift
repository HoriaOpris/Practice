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
    
    func printSudoku(sudoku: [Int]){
        var count = 0;
        
        for nos in sudoku{
            count += 1
            
            print(nos, " ", terminator: "")
            if((count % 3) == 0){
                print()
            }
        }
        print()
    }
    
    func Sudoku(sudoku1: [Int], sudoku4: [Int], sudoku7: [Int]){
        //verify cols
        var cols1 = [sudoku1[0], sudoku1[3], sudoku1[6], sudoku4[0], sudoku4[3], sudoku4[6], sudoku7[0], sudoku7[3], sudoku7[6],]

        //missing numbers
        let expected = [1,2,3,4,5,6,7,8,9]
        var missing = [Int]()
        
        for ex in expected{
            for (index, col) in cols1.enumerated(){
                if(col == ex)
                {
                    break
                }
                else
                {
                    if(index == 8)
                    {
                        missing.append(ex)
                    }
                }
            }
        }
        
        for miss in missing{
            print(miss, terminator: "")
        }
        print()
        printSudoku(sudoku: sudoku1)
        printSudoku(sudoku: sudoku4)
        printSudoku(sudoku: sudoku7)
    }
}

var sol:Solution = Solution()

print("Out:", sol.distributeCandies(candyType: [1,2,3,3,3,3]))

sol.Sudoku(sudoku1: [0,0,0,6,8,0,1,9,0], sudoku4:[8,2,0,0,0,4,0,5,0], sudoku7: [0,0,9,0,4,0,7,0,3])
