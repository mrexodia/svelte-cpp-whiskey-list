<script>
  import { onMount } from "svelte";
  import { apiData, drinkNames } from "./store.js";

  onMount(async () => {
    fetch("http://localhost:8080/data")
      .then((response) => response.json())
      .then((data) => {
        console.log(data);
        apiData.set(data);
      })
      .catch((error) => {
        console.log(error);
        return [];
      });
  });
</script>

<main>
  <h1>Whiskey Drinks Menu</h1>
  <ul>
    {#each $drinkNames as drinkName}
      <li>{drinkName}</li>
    {/each}
  </ul>
</main>

<style>
</style>
