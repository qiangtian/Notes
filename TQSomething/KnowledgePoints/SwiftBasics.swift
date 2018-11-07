//
//  SwiftBasics.swift
//  TQSomething
//
//  Created by 西安旺豆电子 on 2018/4/17.
//  Copyright © 2018年 TQ. All rights reserved.
//

import UIKit

class SwiftBasics: NSObject {

    func test1()  {
        println("ss")
        
        var mystrin:String?
        mystrin = "hello"
        if let yourstr = mystrin {
            print(yourstr)
        } else {
            print("none")
        }
        
        let st1 = "abc"
        let st2 = "123"
        let st3 = st1 + st2
        print(st3)
        st3.hasPrefix("a")
        st3 < st2
        
        // 数组
        var intarr:[Int] = [1,2,3]
        intarr.append(4)
        intarr += [5]
        var somearr = [Int]()
        var arr1 = [Int](repeating: 0, count: 4)
        
        
        for (index, item) in intarr.enumerated() {
            
        }
        
        // 字典
        var dict1 = [Int:String]()
        var dict2:[Int:String] = [1:"one",2:"two"]
        dict2.updateValue("a", forKey: 1)
        dict2[2] = "b"
//        dict2.removeValue(forKey: 2)
        for (key,value) in dict2 {
            print("\(key):\(value)")
        }
        
        let ditkey = [Int](dict2.keys)
        let ditvalue = [Int](dict2.values)
        dict2.count
        
        
    }
    func test2(_ num:Int) -> Int {
        return num
        
        
        
        minMax(array: [1,2])
        test3(arg: 4)
        test4(nums: 1,2,3,4)
        test5(&4)   // &表示这个参数 可以被修改
        ano(add: sum, a: 9, b: 9)
    }
    
    // 元组tuple , 获取数组中最大、最小 数
    func minMax(array:[Int]) -> (min:Int, max:Int)? {
        if array.isEmpty {return nil}
        
        var curMin = array[0]
        var curMax = array[0]
        for value in array[1..<array.count] {
            if value < curMin {
                curMin = value
            } else if value > curMax {
                curMax = value
            }
        }
        return (curMin, curMax)
    }
    // arg 作为外部参数名，num作为内部使用的参数名
    func test3(arg num:Int) -> Int {
        return num
    }
    // 可变参数
    func test4<N>(nums: N...) {
        
    }
    // 可改变值 inout
    func test5(_ a: inout Int) {
        
    }
    func sum(a:Int, b: Int) -> Int {
        
    }
    var add:(Int, Int) -> Int = sum
    func ano(add:(Int, Int) -> Int, a:Int, b:Int) {
        
    }
    
    
    
}

// MARK:- 数据类型
/*
{
    int 在32位平台 Int 和 Int32 长度相同
    64平台，   Int 和 Int64 长度相同
}
 
 类型别名
 typealias feet = Int

 */
