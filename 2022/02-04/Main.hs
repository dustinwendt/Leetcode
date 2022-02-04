module Main where

import Data.Map
import Prelude hiding (insert, lookup)

main = do l <- getLine
          print $ findMaxLength $ read l

findMaxLength :: [Int] -> Int
findMaxLength xs = go 0 xs 0 (insert 0 (-1) empty) 0
  where go :: Int -> [Int] -> Int -> Map Int Int -> Int -> Int
        go _ [] _ _ v       = v
        go idx (x:xs) d m v = if x == 1
                          then case lookup (d+1) m of
                                 Just x -> go (idx+1) xs (d+1) m (max v (idx - x))
                                 Nothing -> go (idx+1) xs (d+1) (insert (d+1) idx m) v
                          else case lookup (d-1) m of
                                 Just x -> go (idx+1) xs (d-1) m (max v (idx - x))
                                 Nothing -> go (idx+1) xs (d-1) (insert (d-1) idx m) v
