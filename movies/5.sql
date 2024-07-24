--SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
SELECT
  title,
  YEAR
FROM
  movies
WHERE
  title LIKE "Harry Potter%"
GROUP BY
  YEAR;