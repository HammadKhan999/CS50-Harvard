-- SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
SELECT
  title,
  rating
FROM
  ratings
  JOIN movies ON movies.id = ratings.movie_id
WHERE
  YEAR = 2010
GROUP BY
  title
ORDER BY
  rating desc,
  title asc;