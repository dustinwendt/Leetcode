module Main where

main = do l <- getLine
          print $ mergeKLists (read l)

mergeKLists :: [[Int]] -> [Int]
mergeKLists [x] = x
mergeKLists (x:y:xs) = mergeKLists (xs ++ [merge x y])

merge :: Ord x => [x] -> [x] -> [x]
merge [] x = x
merge x [] = x
merge (x:xs) (y:ys) = if x < y
                      then x : merge xs (y:ys)
                      else y : merge (x:xs) ys
