main = do
    s <- getLine
    putStrLn $ if head s == s!!1 && head s == last s then "Won" else "Lost"