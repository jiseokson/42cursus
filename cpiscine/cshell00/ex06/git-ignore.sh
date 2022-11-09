find . -type f -exec basename {} \; | git check-ignore --stdin
