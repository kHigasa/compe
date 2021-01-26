let () = Scanf.scanf "%s" (fun s ->
  print_endline @@ if (s.[0]=s.[1] && s.[0]=s.[2]) then "Won" else "Lose")