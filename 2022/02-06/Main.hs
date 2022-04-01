module Main where

main = do
  l <- getLine
  print $ removeDuplicates $ read l

removeDuplicates :: [Int] -> [Int]
removeDuplicates (x:y:xs) | x == y = x : y : removeDuplicates (dropWhile (==x) xs)
                          | otherwise = x : removeDuplicates (y:xs)
removeDuplicates x = x
