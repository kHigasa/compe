{-# LANGUAGE MultiWayIf #-}
main = do
    [a, b, c] <- map read . words <$> getLine
    if
        | a > b     -> putStrLn "Takahashi" 
        | a < b     -> putStrLn "Aoki" 
        | otherwise -> if c == 0 then putStrLn "Takahashi"  else putStrLn "Aoki"